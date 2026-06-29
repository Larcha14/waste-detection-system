CREATE TABLE jobs (
    id SERIAL PRIMARY KEY,
    input_dir TEXT NOT NULL,
    job_status TEXT NOT NULL DEFAULT 'queued'
        CHECK (job_status IN ('queued', 'processing', 'completed', 'failed', 'cancelled')),
    total_images INT NOT NULL DEFAULT 0,
    processed_images INT NOT NULL DEFAULT 0,
    failed_images INT NOT NULL DEFAULT 0,
    created_at TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP,
    updated_at TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP,
    started_at TIMESTAMP,
    finished_at TIMESTAMP
);

CREATE TABLE job_images (
    id SERIAL PRIMARY KEY,
    job_id INT NOT NULL REFERENCES jobs(id) ON DELETE CASCADE,
    image_name TEXT NOT NULL,
    image_path TEXT NOT NULL,
    image_status TEXT NOT NULL DEFAULT 'queued'
        CHECK (image_status IN ('queued', 'processing', 'completed', 'failed', 'skipped')),
    error TEXT,
    created_at TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP,
    updated_at TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP,
    started_at TIMESTAMP,
    finished_at TIMESTAMP,
    UNIQUE (job_id, image_path)
);